package repository;

import domain.User;
import domain.validators.Validator;

import java.util.Properties;

public class RepositoryFactory {
    private Properties properties;

    public RepositoryFactory(Properties properties){
        this.properties = properties;
    }

    public Repository<Long, User> createUserRepository(Validator<User> validator){

    };
}
