package service;

import domain.User;
import domain.validator.ValidationException;
import domain.validator.Validator;
import repository.Repository;
import repository.RepositoryException;

import java.util.Collection;
import java.util.Optional;

/**
 * Service coordinating operations on User entities.
 */
public class UserService {
    private final Repository<Integer, User> repository;
    private final Validator<User> validator;

    public UserService(Repository<Integer, User> repository, Validator<User> validator) {
        this.repository = repository;
        this.validator = validator;
    }

    /**
     * Validates and saves a new user.
     *
     * @param id        user unique identifier
     * @param firstName user's first name
     * @param lastName  user's last name
     * @throws ValidationException if user data is invalid
     * @throws RepositoryException if a user with the same ID already exists
     */
    public void addUser(Integer id, String firstName, String lastName) {
        User user = new User(id, firstName, lastName);
        // Validam o singura data, aici in Service!
        validator.validate(user);
        repository.add(user);
    }

    /**
     * Removes a user by identifier.
     *
     * @param id the ID of the user to delete
     * @throws ServiceException if no user with the given ID exists
     */
    public void removeUser(Integer id) {
        Optional<User> removed = repository.remove(id);
        if (removed.isEmpty()) {
            throw new ServiceException("User with ID " + id + " does not exist and cannot be deleted!");
        }
    }

    /**
     * Finds a user by identifier.
     *
     * @param id user ID
     * @return the User instance
     * @throws ServiceException if the user was not found
     */
    public User findUserById(Integer id) {
        Optional<User> user = repository.findById(id);
        if (user.isEmpty()) {
            throw new ServiceException("User with ID " + id + " does not exist!");
        }
        return user.get();
    }

    /**
     * Retrieves all registered users.
     *
     * @return collection of all users
     */
    public Collection<User> getAllUsers() {
        return repository.findAll();
    }
}