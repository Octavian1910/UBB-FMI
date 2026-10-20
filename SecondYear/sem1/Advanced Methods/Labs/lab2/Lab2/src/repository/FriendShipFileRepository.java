package repository;

import domain.FriendShip;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class FriendShipRepository implements Repository<FriendShip, FriendShip> {
    private final Set<FriendShip> friendShips = new HashSet<>();
    private final String file_path;

    public FriendShip(String file_path) {
        this.file_path = file_path;
        loadFromFile();
    }

    private void loadFromFile() {
        File file = new File(file_path);
        if (!file.exists()) {
            return;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) {
                    continue;
                }
                String[] fields = line.split("\\|");

                if (fields.length != 2) {
                    throw new RepositoryException("Invalid friendship line: " + line);
                }
                int firstUserId = Integer.parseInt(fields[0].trim());
                int secondUserId = Integer.parseInt(fields[1].trim());
                FriendShip friendShip = new FriendShip(firstUserId,secondUserId);
                friendShips.put(friendShip,friendShip);

            }
        }catch (IOException e){
            throw new RepositoryException()
        }
    }

    @Override
    public void add(FriendShip friendShip) {
        if (!friendShips.add(friendShip)) {
            throw new RepositoryException("Friendship already exists!");
        }
    }

    @Override
    public Optional<FriendShip> remove(FriendShip friendShip) {
        if (friendShips.remove(friendShip)) {
            return Optional.of(friendShip);
        }
        return Optional.empty();
    }

    @Override
    public Collection<FriendShip> findAll() {
        return friendShips.stream().filter()
    }
}
