/*
 CRUD operations repository interface
 @param<ID> type E must have an attribute of type ID
 @parma >E? type of entities saved in repository
* */
public interface Repository<ID,E extends Entity<ID>> {
    E findOne(ID id);
    Iterable<E> findAll();
    E save(E entity);

    E delete(ID id);

    E update(E entity);

}
