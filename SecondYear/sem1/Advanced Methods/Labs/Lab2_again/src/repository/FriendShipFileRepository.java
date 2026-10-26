package repository;

import domain.FriendShip;

import java.time.DateTimeException;
import java.time.LocalDateTime;
import java.util.Collection;
import java.util.Date;
import java.util.Optional;

public class FriendShipFileRepository extends AbstractFileRepository<String, FriendShip> {
    public FriendShipFileRepository(String filePath) {
        super(filePath);
    }

    @Override
    protected FriendShip extractEntity(String line) {
        String[] fields = line.split(";", -1);
        if (fields.length != 3) {
            throw new RepositoryException("Invalid freindship line format: " + line);
        }
        try {
            int firstUserrId = Integer.parseInt(fields[0].trim());
            int secondUserId = Integer.parseInt(fields[1].trim());
            LocalDateTime date = LocalDateTime.parse(fields[2].trim());
            return new FriendShip(firstUserrId, secondUserId, date);
        } catch (NumberFormatException e) {
            throw new RepositoryException("Invalid user IDs in friendship: " + line, e);
        } catch (DateTimeException e) {
            throw new RepositoryException("Ivalid ISO date format: " + line, e);
        }
    }

    private String normalizedId(String id) {
        if (id == null) {
            throw new IllegalArgumentException("ID cannot be null!");
        }
        String[] parts = id.split("-", -1);
        if (parts.length != 2) {
            throw new RepositoryException("Invalid friendship ID format:" + id);
        }
        try {
            int firstId = Integer.parseInt(parts[0].trim());
            int secondId = Integer.parseInt(parts[1].trim());
            return Math.min(firstId, secondId) + "-" + Math.max(firstId, secondId);
        } catch (NumberFormatException e) {
            throw new RepositoryException("Invalid numeric IDs: " + id, e);
        }
    }

    @Override
    protected String createEntityAsString(FriendShip friendShip) {
        return friendShip.getFirstUserId() + ";" +
                friendShip.getSecondUserId() + ";" +
                friendShip.getDate();
    }

    @Override
    public Optional<FriendShip> findById(String id) {
        return super.remove(normalizedId(id));
    }

    @Override
    public Optional<FriendShip> remove(String id) {
        return super.remove(normalizedId(id));
    }
}
