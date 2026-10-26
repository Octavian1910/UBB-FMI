package repository;

import domain.Entity;

import java.util.Collection;
import java.util.Optional;

/**
 * Generic CRUD repository interface.
 *
 * @param <ID> the entity identifier type
 * @param <E>  the entity type extending {@link Entity}
 */
public interface Repository<ID, E extends Entity<ID>> {

    /**
     * Saves an entity into persistence.
     *
     * @param entity the entity to store, must not be null
     * @throws IllegalArgumentException if entity is null or entity.getId() is null
     * @throws RepositoryException      if an entity with the same ID already exists
     */
    void add(E entity);

    /**
     * Removes an entity by its identifier.
     *
     * @param id identifier of the entity, must not be null
     * @return an {@link Optional} containing the removed entity, or empty if absent
     * @throws IllegalArgumentException if id is null
     */
    Optional<E> remove(ID id);

    /**
     * Finds an entity by its identifier.
     *
     * @param id identifier to search for, must not be null
     * @return an {@link Optional} containing the found entity, or empty if absent
     * @throws IllegalArgumentException if id is null
     */
    Optional<E> findById(ID id);

    /**
     * Retrieves all stored entities.
     *
     * @return a {@link Collection} of all stored entities
     */
    Collection<E> findAll();

    /**
     * Updates an existing entity.
     *
     * @param entity the updated entity state, must not be null
     * @return {@link Optional#empty()} if updated, or Optional of entity if it does not exist
     * @throws IllegalArgumentException if entity is null or entity.getId() is null
     */
    Optional<E> update(E entity);
}