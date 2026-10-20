package repository;

import java.util.Collection;
import java.util.List;
import java.util.Optional;

public class InMemoryRepository implements Repository{
    @Override
    public void add(Object entity) {

    }

    @Override
    public Optional remove(Object o) {
        return Optional.empty();
    }

    @Override
    public Collection findAll() {
        return List.of();
    }

    @Override
    public Optional findById(Object o) {
        return Optional.empty();
    }
}
