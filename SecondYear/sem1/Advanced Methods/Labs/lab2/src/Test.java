import domain.FriendShip;
import domain.User;
import domain.validator.FriendShipValidator;
import domain.validator.UserValidator;
import domain.validator.ValidationException;
import repository.FriendShipFileRepository;
import repository.InMemoryRepository;
import repository.RepositoryException;
import repository.UserFileRepository;
import service.FriendShipService;
import service.NetworkService;
import service.ServiceException;
import service.UserService;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Set;

public class Test {

    private static final String USERS_FILE = "test_users.txt";
    private static final String FRIENDSHIPS_FILE = "test_friendships.txt";
    private static final String CORRUPTED_USERS_FILE = "test_corrupted_users.txt";

    public static void runAll() {
        testDomainAndValidators();
        testRepositories();
        testCorruptedFiles();
        testUserService();
        testFriendShipService();
        testNetworkService();
        System.out.println("All tests passed successfully!");
    }

    private static void resetFiles() {
        writeFile(USERS_FILE,
                "1;Ana;Pop",
                "2;Ion;Ionescu",
                "3;Maria;Marin",
                "4;Alex;Pop",
                "5;Elena;Matei",
                "6;George;Vasile",
                "7;Cristina;Stan",
                "8;Dan;Dumitru",
                "9;Radu;Enache",
                "10;Ioana;Micu"
        );

        writeFile(FRIENDSHIPS_FILE,
                "1;2;2026-10-19T10:30:00",
                "2;3;2026-10-19T11:00:00",
                "3;4;2026-10-19T11:30:00",
                "4;5;2026-10-19T12:00:00",
                "6;7;2026-10-20T09:00:00",
                "7;8;2026-10-20T09:30:00",
                "6;8;2026-10-20T10:00:00",
                "9;10;2026-10-20T10:30:00"
        );

        writeFile(CORRUPTED_USERS_FILE,
                "1;Mihai;Popescu",
                "2;Elena",
                "abc;Andrei;Radu",
                "4;Ioana;Dumitrescu",
                "cinci;Cristian;Stan",
                "6;George;Vasile;ExtraField",
                "7;Vlad;Munteanu"
        );
    }

    private static void testDomainAndValidators() {
        User u1 = new User(1, "Ana", "Pop");
        User u2 = new User(1, "AltNume", "AltPrenume");
        User u3 = new User(2, "Ion", "Ionescu");
        assert u1.equals(u2) && !u1.equals(u3);
        assert u1.getId() == 1 && u1.getFirstName().equals("Ana") && u1.getLastName().equals("Pop");

        UserValidator userVal = new UserValidator();
        userVal.validate(u1);

        try {
            userVal.validate(null);
            assert false;
        } catch (ValidationException e) {
            assert e.getMessage().contains("null");
        }

        try {
            userVal.validate(new User(-1, "ana", ""));
            assert false;
        } catch (ValidationException e) {
            assert e.getMessage().contains("positive") &&
                    e.getMessage().contains("uppercase") &&
                    e.getMessage().contains("empty");
        }

        FriendShip f1 = new FriendShip(1, 2);
        FriendShip f2 = new FriendShip(2, 1);
        assert f1.equals(f2) && f1.getId().equals("1-2") && f2.getId().equals("1-2");

        FriendShipValidator fsVal = new FriendShipValidator();
        fsVal.validate(f1);

        try {
            fsVal.validate(new FriendShip(1, 1));
            assert false;
        } catch (ValidationException e) {
            assert e.getMessage().contains("themselves");
        }

        try {
            fsVal.validate(new FriendShip(-1, 0));
            assert false;
        } catch (ValidationException e) {
            assert e.getMessage().contains("positive");
        }
    }

    private static void testRepositories() {
        resetFiles();

        InMemoryRepository<Integer, User> memRepo = new InMemoryRepository<>();
        memRepo.add(new User(11, "Radu", "Iliescu"));
        assert memRepo.findAll().size() == 1 && memRepo.findById(11).isPresent();

        try {
            memRepo.add(new User(11, "Alt", "Nume"));
            assert false;
        } catch (RepositoryException e) {
            assert e.getMessage().contains("already exists");
        }

        assert memRepo.remove(999).isEmpty();
        assert memRepo.remove(11).isPresent() && memRepo.findAll().isEmpty();

        UserFileRepository userRepo = new UserFileRepository(USERS_FILE);
        assert userRepo.findAll().size() == 10 && userRepo.findById(1).isPresent() && userRepo.findById(999).isEmpty();

        try {
            userRepo.add(new User(1, "Duplicat", "Nume"));
            assert false;
        } catch (RepositoryException e) {
            assert e.getMessage().contains("already exists");
        }

        userRepo.add(new User(11, "Paul", "Enache"));
        assert userRepo.findAll().size() == 11;

        FriendShipFileRepository fsRepo = new FriendShipFileRepository(FRIENDSHIPS_FILE);
        assert fsRepo.findAll().size() == 8;
        assert fsRepo.findById("2-1").isPresent() && fsRepo.findById("8-7").isPresent() && fsRepo.findById("10-1").isEmpty();

        try {
            fsRepo.add(new FriendShip(2, 1));
            assert false;
        } catch (RepositoryException e) {
            assert e.getMessage().contains("already exists");
        }

        assert fsRepo.remove("999-1000").isEmpty();
        assert fsRepo.remove("10-9").isPresent() && fsRepo.findAll().size() == 7;
    }

    private static void testCorruptedFiles() {
        resetFiles();
        UserFileRepository corruptRepo = new UserFileRepository(CORRUPTED_USERS_FILE);

        assert corruptRepo.findAll().size() == 3;
        assert corruptRepo.findById(1).isPresent();
        assert corruptRepo.findById(4).isPresent();
        assert corruptRepo.findById(7).isPresent();
        assert corruptRepo.findById(2).isEmpty();
        assert corruptRepo.findById(6).isEmpty();
    }

    private static void testUserService() {
        resetFiles();
        UserValidator validator = new UserValidator();
        UserFileRepository repo = new UserFileRepository(USERS_FILE);
        UserService service = new UserService(repo, validator);

        assert service.getAllUsers().size() == 10;
        assert service.findUserById(1).getFirstName().equals("Ana");

        try {
            service.findUserById(999);
            assert false;
        } catch (ServiceException e) {
            assert e.getMessage().contains("does not exist");
        }

        try {
            service.addUser(-1, "Ion", "Pop");
            assert false;
        } catch (ValidationException e) {
            assert e.getMessage().contains("positive");
        }

        try {
            service.addUser(1, "Alt", "Nume");
            assert false;
        } catch (RepositoryException e) {
            assert e.getMessage().contains("already exists");
        }

        service.addUser(11, "George", "Vasile");
        assert service.getAllUsers().size() == 11;

        try {
            service.removeUser(999);
            assert false;
        } catch (ServiceException e) {
            assert e.getMessage().contains("cannot be deleted");
        }

        service.removeUser(11);
        assert service.getAllUsers().size() == 10;
    }

    private static void testFriendShipService() {
        resetFiles();
        UserValidator userVal = new UserValidator();
        FriendShipValidator fsVal = new FriendShipValidator();

        UserService userService = new UserService(new UserFileRepository(USERS_FILE), userVal);
        FriendShipFileRepository fsRepo = new FriendShipFileRepository(FRIENDSHIPS_FILE);
        FriendShipService service = new FriendShipService(fsRepo, userService, fsVal);

        assert service.getAllFriendShips().size() == 8;
        assert service.getFriendIds(2).contains(1) && service.getFriendIds(2).contains(3);

        try {
            service.addFriendShip(1, 1);
            assert false;
        } catch (ValidationException e) {
            assert e.getMessage().contains("themselves");
        }

        try {
            service.addFriendShip(1, 999);
            assert false;
        } catch (ServiceException e) {
            assert e.getMessage().contains("does not exist");
        }

        try {
            service.addFriendShip(2, 1);
            assert false;
        } catch (RepositoryException e) {
            assert e.getMessage().contains("already exists");
        }

        try {
            service.removeFriendShip(1, 10);
            assert false;
        } catch (ServiceException e) {
            assert e.getMessage().contains("does not exist");
        }

        service.addFriendShip(1, 10);
        assert service.getAllFriendShips().size() == 9 && service.getFriendIds(1).contains(10);

        service.removeFriendShip(10, 1);
        assert service.getAllFriendShips().size() == 8 && !service.getFriendIds(1).contains(10);

        service.removeAllFriendshipsOfUser(7);
        assert service.getFriendIds(7).isEmpty() && service.getAllFriendShips().size() == 6;
    }

    private static void testNetworkService() {
        resetFiles();
        UserValidator userVal = new UserValidator();
        FriendShipValidator fsVal = new FriendShipValidator();

        UserService userService = new UserService(new UserFileRepository(USERS_FILE), userVal);
        FriendShipService fsService = new FriendShipService(new FriendShipFileRepository(FRIENDSHIPS_FILE), userService, fsVal);
        NetworkService networkService = new NetworkService(userService, fsService);

        assert networkService.getNumberOfCommunities() == 3;

        Set<Integer> comm1 = networkService.getCommunity(1);
        assert comm1.size() == 5 && comm1.contains(1) && comm1.contains(5);

        Set<Integer> comm2 = networkService.getCommunity(7);
        assert comm2.size() == 3 && comm2.contains(6) && comm2.contains(8);

        Set<Integer> comm3 = networkService.getCommunity(10);
        assert comm3.size() == 2 && comm3.contains(9) && comm3.contains(10);

        try {
            networkService.getCommunity(999);
            assert false;
        } catch (ServiceException e) {
            assert e.getMessage().contains("does not exist");
        }

        Set<Integer> mostSociable = networkService.getMostSociableCommunity();
        assert mostSociable.size() == 5 && mostSociable.contains(1) && mostSociable.contains(5);

        try {
            networkService.removeUserAndFriendships(999);
            assert false;
        } catch (ServiceException e) {
            assert e.getMessage().contains("cannot be deleted");
        }

        networkService.removeUserAndFriendships(3);
        assert userService.getAllUsers().size() == 9;
        assert fsService.getFriendIds(2).size() == 1 && fsService.getFriendIds(4).size() == 1;
        assert networkService.getNumberOfCommunities() == 4;

        Set<Integer> splitA = networkService.getCommunity(1);
        Set<Integer> splitB = networkService.getCommunity(5);
        assert splitA.size() == 2 && splitB.size() == 2;
    }

    private static void writeFile(String path, String... lines) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(path))) {
            for (String line : lines) {
                writer.write(line);
                writer.newLine();
            }
        } catch (IOException e) {
            throw new RuntimeException("Eroare la scrierea fisierului: " + path, e);
        }
    }
}