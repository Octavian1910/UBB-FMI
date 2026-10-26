package repository.db;

import domain.User;
import domain.validators.Validator;
import repository.Repository;

public class UtilizatorDbRepository implements Repository<Long, User> {
    private Validator<User> validator;
    private String url;
    private String username;
    private String password;

    public UtilizatorDbRepository(Validator<User> validator,String url,String username,String password){
        this.validator = validator;
        this.url = url;
        this.username = username;
        this.password = password;
    }


    @Override
    public User save(User entity) {
        throw new UnsupportedOperationException("save not supported");
    }

    @Override
    public User delete(Long aLong) {
        throw new UnsupportedOperationException("delete not supported");
    }

    @Override
    public User update(User entity) {
        throw new UnsupportedOperationException("update not supported");
    }

    @Override
    public Iterable<User> findAll() {
        throw new UnsupportedOperationException("findAll not supported");
    }

    @Override
    public User findOne(Long aLong) {
        throw new UnsupportedOperationException("findOne not supported");
    }
}
