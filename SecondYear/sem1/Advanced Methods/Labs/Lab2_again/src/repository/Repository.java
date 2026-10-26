package repository;

import domain.Entity;

import java.util.Collection;
import java.util.Optional;

public interface Repository<ID, E extends Entity<ID>> {
    void add(E entity);

    Optional<E> remove(ID id);

    Optional<E> findById(ID id);

    Collection<E> findAll();

    Optional<E> update(E entity);


}
