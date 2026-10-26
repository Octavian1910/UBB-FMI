package repository;

import domain.Entity;

import java.util.*;

public class InMemoryRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {

    protected final Map<ID, E> entities = new HashMap<>();

    @Override
    public void add(E entity) {
        if (entity == null)
            throw new IllegalArgumentException("Entity cannot be null!");

        ID id = entity.getId();
        if (id == null)
            throw new IllegalArgumentException("Entity ID cannnot be null!");
        if (entities.containsKey(id)) {
            throw new RepositoryException("Entity with ID " + id + "already exists!");
        }
        entities.put(id, entity);
    }

    @Override
    public Optional<E> update(E entity) {
        if (entity == null) {
            throw new IllegalArgumentException("Entity cannot be null!");
        }
        ID id = entity.getId();
        if (id == null) {
            throw new IllegalArgumentException("Entity ID cannot be null!");
        }
        if (!entities.containsKey(id)) {
            return Optional.of(entity); //trimitem obiectul inapoi daca nu exista deja un obiect cu acest id atribuit in map
        }
        entities.put(id, entity);
        return Optional.empty();
    }

    @Override
    public Optional<E> remove(ID id) {
        if (id == null){
            throw new IllegalArgumentException("Entity cannot be null!");
        }
        return Optional.ofNullable(entities.get(id));
    }

    @Override
    public Collection<E> findAll() {
        return new ArrayList<>(entities.values());
    }

    @Override
    public Optional<E> findById(ID id) {
        if (id == null){
            throw new IllegalArgumentException("ID cannot be null!");
        }
        return Optional.ofNullable(entities.get(id));
    }
}
