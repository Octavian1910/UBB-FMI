import domain.FriendShip;
import domain.User;
import domain.validator.UserValidator;
import repository.Repository;
import repository.UserFileRepository;
import repository.factory.RepositoryFactory;
import service.UserService;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        RepositoryFactory repositoryFactory = new RepositoryFactory("config.properties");

        UserValidator userValidator = new UserValidator();

        Repository<Integer, User> userRepository = repositoryFactory.createUserRepository();
        Repository<String, FriendShip> friendShipRepository = repositoryFactory.createFriendshipRepository();

        UserService userService = new UserService(userRepository,userRepository);


    }
}