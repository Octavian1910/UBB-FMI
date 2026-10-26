package service;

import domain.FriendShip;
import repository.Repository;
import repository.RepositoryException;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Optional;

/**
 * Service coordinating friendship relationships between users.
 */
public class FriendShipService {
    private final Repository<String, FriendShip> repository;
    private final UserService userService;

    public FriendShipService(Repository<String, FriendShip> repository, UserService userService) {
        this.repository = repository;
        this.userService = userService;
    }

    /**
     * Adds a friendship between two existing users.
     *
     * @param firstUserId  first user ID
     * @param secondUserId second user ID
     * @throws ServiceException    if IDs are identical or users do not exist
     * @throws RepositoryException if the friendship already exists
     */
    public void addFriendShip(int firstUserId, int secondUserId) {
        if (firstUserId == secondUserId) {
            throw new ServiceException("A user cannot be friends with themselves!");
        }
        // Verificam existenta ambilor utilizatori
        userService.findUserById(firstUserId);
        userService.findUserById(secondUserId);

        FriendShip friendShip = new FriendShip(firstUserId, secondUserId);
        repository.add(friendShip);
    }

    /**
     * Removes a friendship between two users.
     *
     * @param firstUserId  first user ID
     * @param secondUserId second user ID
     * @throws ServiceException if the friendship does not exist
     */
    public void removeFriendShip(int firstUserId, int secondUserId) {
        FriendShip friendShip = new FriendShip(firstUserId, secondUserId);
        Optional<FriendShip> removed = repository.remove(friendShip.getId());
        if (removed.isEmpty()) {
            throw new ServiceException("Friendship does not exist!");
        }
    }

    /**
     * Retrieves all recorded friendships.
     *
     * @return collection of all friendships
     */
    public Collection<FriendShip> getAllFriendShips() {
        return repository.findAll();
    }

    /**
     * Returns the IDs of all friends of a specified user (graph adjacency list).
     *
     * @param userId the user ID
     * @return collection containing all friend IDs
     */
    public Collection<Integer> getFriendIds(int userId) {
        Collection<Integer> friendIds = new ArrayList<>();
        for (FriendShip fs : repository.findAll()) {
            if (fs.getFirstUserId() == userId) {
                friendIds.add(fs.getSecondUserId());
            } else if (fs.getSecondUserId() == userId) {
                friendIds.add(fs.getFirstUserId());
            }
        }
        return friendIds;
    }

    /**
     * Removes all friendships associated with a user.
     *
     * @param userId the user ID
     */
    public void removeAllFriendshipsOfUser(int userId) {
        List<Integer> friends = new ArrayList<>(getFriendIds(userId));
        for (Integer friendId : friends) {
            removeFriendShip(userId, friendId);
        }
    }
}