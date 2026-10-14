import model.Entity;
import repository.Repository;

import java.util.Map;

public class InMemoryRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {

    private Map<ID,E> map;

    InMemoryRepository
}