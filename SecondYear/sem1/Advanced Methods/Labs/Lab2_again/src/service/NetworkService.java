package service;

import domain.User;

import java.nio.MappedByteBuffer;
import java.util.*;

/**
 * Service responsible for graph-related social network analysis.
 */
public class NetworkService {
    // Dependintele sunt finale si injectate prin constructor (Dependency Injection)
    private final UserService userService;
    private final FriendShipService friendShipService;

    public NetworkService(UserService userService, FriendShipService friendShipService) {
        this.userService = userService;
        this.friendShipService = friendShipService;
    }


    private void dfs(int userId, Set<Integer> visited) {
        visited.add(userId);
        Collection<Integer> friends = friendShipService.getFriendIds(userId);
        for (Integer friendId : friends) {
            if (!visited.contains(friendId)) {
                dfs(friendId, visited);
            }
        }
    }

    public int getNumberOfCommunities() {
        Set<Integer> visited = new HashSet<>();
        int numberOfCommunities = 0;

        for (User user : userService.getAllUsers()) {
            if (!visited.contains(user.getId())) {
                dfs(user.getId(), visited);
                numberOfCommunities++;
            }
        }
        return numberOfCommunities;
    }

    public Set<Integer> getCommunity(int userId) {
        Set<Integer> community = new HashSet<>();
        userService.findUserById(userId);
        dfs(userId, community);
        return community;
    }

    /**
     * Computes the shortest distance between two nodes via Breadth-First Search (BFS).
     *
     * @param startId  source user ID
     * @param targetId destination user ID
     * @return the minimum number of edges between startId and targetId, or -1 if disconnected
     */
    private int getDistance(int startId, int targetId) {
        Queue<Integer> queue = new LinkedList<>();
        Map<Integer, Integer> distances = new HashMap<>();

        queue.add(startId);
        distances.put(startId, 0);

        while (!queue.isEmpty()) {
            int currentId = queue.poll();

            // Daca am ajuns la nodul destinatie, returnam direct distanta minima
            if (currentId == targetId) {
                return distances.get(currentId);
            }

            // Extragem toti prietenii nodului curent
            for (Integer friendId : friendShipService.getFriendIds(currentId)) {
                if (!distances.containsKey(friendId)) {
                    distances.put(friendId, distances.get(currentId) + 1);
                    queue.add(friendId);
                }
            }
        }

        return -1; // Nodurile nu sunt conectate
    }


    /**
     * Determines the most sociable community (connected component with the longest shortest path).
     *
     * @return a Set containing the user IDs in the most sociable community
     */
    public Set<Integer> getMostSociableCommunity() {
        Set<Integer> visited = new HashSet<>();
        Set<Integer> bestCommunity = new HashSet<>();
        int longestDistance = -1;

        // 1. Gasim fiecare componenta conexa pe rand
        for (User user : userService.getAllUsers()) {
            if (visited.contains(user.getId())) {
                continue;
            }

            Set<Integer> community = new HashSet<>();
            dfs(user.getId(), community);
            visited.addAll(community);

            // 2. Calculam cel mai lung drum minim din aceasta componenta (diametrul)
            int communityLongestDistance = 0;
            for (Integer user1 : community) {
                for (Integer user2 : community) {
                    int distance = getDistance(user1, user2);
                    if (distance > communityLongestDistance) {
                        communityLongestDistance = distance;
                    }
                }
            }

            // 3. Verificam daca bate recordul anterior
            if (communityLongestDistance > longestDistance) {
                longestDistance = communityLongestDistance;
                bestCommunity = community;
            }
        }

        return bestCommunity;
    }


    /**
     * Cascading deletion: removes a user and all their associated friendships from the network.
     * Ensures consistency between both data stores.
     *
     * @param userId the ID of the user to be removed
     * @throws ServiceException if the user does not exist
     */
    public void removeUserAndFriendships(int userId) {
        // 1. Stergem toate relatiile de prietenie in care apare acest user
        // (FriendShipFileRepository rescrie automat friendships.txt fara ele)
        friendShipService.removeAllFriendshipsOfUser(userId);

        // 2. Stergem utilizatorul din sistem
        // (UserFileRepository rescrie automat users.txt fara el)
        userService.removeUser(userId);
    }
}