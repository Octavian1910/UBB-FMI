package service;

import domain.User;

import java.util.*;

/**
 * Service responsible for graph-related social network analysis.
 */
public class NetworkService {
    private final UserService userService;
    private final FriendShipService friendShipService;

    public NetworkService(UserService userService, FriendShipService friendShipService) {
        this.userService = userService;
        this.friendShipService = friendShipService;
    }

    /**
     * Computes the shortest path between two nodes using Breadth-First Search (BFS).
     *
     * @param startId  source user ID
     * @param targetId destination user ID
     * @return shortest distance, or -1 if unreachable
     */
    private int getDistance(int startId, int targetId) {
        Queue<Integer> queue = new LinkedList<>();
        Map<Integer, Integer> distances = new HashMap<>();

        queue.add(startId);
        distances.put(startId, 0);

        while (!queue.isEmpty()) {
            int currentId = queue.poll();
            if (currentId == targetId) {
                return distances.get(currentId);
            }

            for (Integer friendId : friendShipService.getFriendIds(currentId)) {
                if (!distances.containsKey(friendId)) {
                    distances.put(friendId, distances.get(currentId) + 1);
                    queue.add(friendId);
                }
            }
        }
        return -1;
    }

    /**
     * Traverses a connected component using recursive Depth-First Search (DFS).
     *
     * @param userId  starting user ID
     * @param visited set tracking visited nodes
     */
    private void dfs(int userId, Set<Integer> visited) {
        visited.add(userId);
        for (Integer friendId : friendShipService.getFriendIds(userId)) {
            if (!visited.contains(friendId)) {
                dfs(friendId, visited);
            }
        }
    }

    /**
     * Computes the total number of communities (connected components) in the network.
     *
     * @return count of connected components
     */
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

    /**
     * Determines the most sociable community (connected component with the longest path).
     *
     * @return set of user IDs forming the most sociable community
     */
    public Set<Integer> getMostSociableCommunity() {
        Set<Integer> visited = new HashSet<>();
        Set<Integer> bestCommunity = new HashSet<>();
        int longestDistance = -1;

        for (User user : userService.getAllUsers()) {
            if (visited.contains(user.getId())) {
                continue;
            }

            Set<Integer> community = new HashSet<>();
            dfs(user.getId(), community);
            visited.addAll(community);

            int communityLongestDistance = 0;
            for (Integer user1 : community) {
                for (Integer user2 : community) {
                    int distance = getDistance(user1, user2);
                    if (distance > communityLongestDistance) {
                        communityLongestDistance = distance;
                    }
                }
            }

            if (communityLongestDistance > longestDistance) {
                longestDistance = communityLongestDistance;
                bestCommunity = community;
            }
        }
        return bestCommunity;
    }

    /**
     * Removes a user and all their associated friendships, ensuring storage consistency.
     *
     * @param userId user ID to delete
     */
    public void removeUserAndFriendships(int userId) {
        friendShipService.removeAllFriendshipsOfUser(userId);
        userService.removeUser(userId);
    }

    /**
     * Retrieves the community (connected component) containing the specified user.
     *
     * @param userId user ID
     * @return set of user IDs belonging to that community
     * @throws ServiceException if the user does not exist
     */
    public Set<Integer> getCommunity(int userId) {
        Set<Integer> community = new HashSet<>();
        userService.findUserById(userId);
        dfs(userId, community);
        return community;
    }
}