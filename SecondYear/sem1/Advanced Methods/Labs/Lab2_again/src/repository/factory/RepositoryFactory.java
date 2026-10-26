package repository.factory;

import domain.FriendShip;
import domain.User;
import repository.*;

import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

/**
 * Simple Factory responsible for instantiating the appropriate concrete {@link Repository}
 * based on the configuration provided in an external properties file.
 */
public class RepositoryFactory {
    private final RepositoryType repositoryType;
    private final Properties properties = new Properties();

    /**
     * Constructs a RepositoryFactory and loads application persistence configurations.
     *
     * @param configFilePath the path to the configuration file (e.g., "config.properties")
     * @throws RepositoryException if the file cannot be read or contains an invalid repository type
     */
    public RepositoryFactory(String configFilePath) {
        // 1. Open and load the properties configuration file
        try (FileReader reader = new FileReader(configFilePath)) {
            properties.load(reader);
        } catch (IOException e) {
            throw new RepositoryException("Failed to read configuration file: " + configFilePath, e);
        }

        // 2. Retrieve repository.type and parse into the RepositoryType enum
        String typeStr = properties.getProperty("repository.type");
        if (typeStr == null || typeStr.trim().isEmpty()) {
            throw new RepositoryException("Missing required configuration key: 'repository.type'");
        }

        try {
            this.repositoryType = RepositoryType.valueOf(typeStr.trim().toUpperCase());
        } catch (IllegalArgumentException e) {
            throw new RepositoryException("Unknown repository type configured: " + typeStr, e);
        }
    }

    /**
     * Creates and returns a repository managing {@link User} entities.
     *
     * @return a concrete implementation of {@link Repository} for users
     * @throws RepositoryException if required configuration keys are missing or type is unsupported
     */
    public Repository<Integer, User> createUserRepository() {
        switch (repositoryType) {
            case MEMORY:
                return new InMemoryRepository<>();
            case FILE:
                String userFile = properties.getProperty("file.users");
                if (userFile == null || userFile.trim().isEmpty()) {
                    throw new RepositoryException("Missing required configuration property: 'file.users'");
                }
                return new UserFileRepository(userFile);
            case DATABASE:
                return new UserDbRepository(
                        properties.getProperty("db.url"),
                        properties.getProperty("db.user"),
                        properties.getProperty("db.password")
                );
            default:
                throw new RepositoryException("Unsupported repository type: " + repositoryType);
        }
    }

    /**
     * Creates and returns a repository managing {@link FriendShip} entities.
     *
     * @return a concrete implementation of {@link Repository} for friendships
     * @throws RepositoryException if required configuration keys are missing or type is unsupported
     */
    public Repository<String, FriendShip> createFriendshipRepository() {
        switch (repositoryType) {
            case MEMORY:
                return new InMemoryRepository<>();
            case FILE:
                String friendshipFile = properties.getProperty("file.friendships");
                if (friendshipFile == null || friendshipFile.trim().isEmpty()) {
                    throw new RepositoryException("Missing required configuration property: 'file.friendships'");
                }
                return new FriendShipFileRepository(friendshipFile);
            case DATABASE:
                return new FriendShipDbRepository(
                        properties.getProperty("db.url"),
                        properties.getProperty("db.user"),
                        properties.getProperty("db.password")
                );
            default:
                throw new RepositoryException("Unsupported repository type: " + repositoryType);
        }
    }

    /*
     * Optional backward-compatibility aliases in case automated tests
     * or lab requirements specifically look for Romanian method names.
     */
    public Repository<Integer, User> createUtilizatorRepository() {
        return createUserRepository();
    }

    public Repository<String, FriendShip> createPrietenieRepository() {
        return createFriendshipRepository();
    }
}