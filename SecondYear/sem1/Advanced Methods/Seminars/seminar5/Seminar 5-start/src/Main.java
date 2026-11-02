import domain.Entity;
import domain.User;
import domain.validators.UserValidator;
import domain.validators.UserValidatorStrict;
import domain.validators.ValidationException;
import domain.validators.Validator;
import repository.InMemoryRepository;
import repository.Repository;
import repository.factory.RepositoryFactory;
import repository.file.UserFileRepository;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        User u = new User("John", "Doe");
        System.out.println(u instanceof Entity);
        requirement1();
        requirement2();
        requirement3();
        requirement4();
    }

    public static void verificaPrenume(User u){
        if (u == null || u.getFirstName() == null || u.getFirstName().isBlank()){
            throw new ValidationException("Prenumele poate lipsi");
        }
    }


    static void requirement7() {
        System.out.println("\n=== Cerința 7. Validator ca expresie lambda ===");

        User invalidUser = getUserFromText("7;;Pop");

        // 1. Clasă anonima
        Validator<User> vAnonim = new Validator<User>() {
            @Override
            public void validate(User entity) {
                if (entity == null || entity.getFirstName() == null || entity.getFirstName().isBlank()) {
                    throw new ValidationException("Prenumele nu poate lipsi! (clasă anonimă)");
                }
            }
        };

        // 2. Expresie lambda
        Validator<User> vLambda = u -> {
            if (u == null || u.getFirstName() == null || u.getFirstName().isBlank()) {
                throw new ValidationException("Prenumele nu poate lipsi! (lambda)");
            }
        };

        // 3. Referința la metoda statica Main::verificaPrenume
        Validator<User> vMethodRef = Main::verificaPrenume;

        // Testăm cele trei validatoare pe utilizatorul 7;;Pop
        System.out.println("-- Testare cele 3 modalități pe 7;;Pop --");
        testeazaValidator(vAnonim, invalidUser, "Clasă Anonimă");
        testeazaValidator(vLambda, invalidUser, "Expresie Lambda");
        testeazaValidator(vMethodRef, invalidUser, "Referință Metodă");


        System.out.println("\n-- Compunere cu andThen și salvare în InMemoryRepository --");

        Validator<User> validatorBaza = new UserValidator();

        Validator<User> lungimeMaxima10 = u -> {
            if (u != null) {
                if (u.getFirstName() != null && u.getFirstName().length() > 10) {
                    throw new ValidationException("Prenumele depășește 10 caractere: " + u.getFirstName());
                }
                if (u.getLastName() != null && u.getLastName().length() > 10) {
                    throw new ValidationException("Numele depășește 10 caractere: " + u.getLastName());
                }
            }
        };

        Validator<User> validatorCompus = validatorBaza.andThen(lungimeMaxima10);

        Repository<Long, User> repoCompus = new InMemoryRepository<>(validatorCompus);

        save(repoCompus, getUserFromText("1;Ana;Pop"));
        save(repoCompus, getUserFromText("2;Maximilian-Alexandru;Pop"));
        save(repoCompus, getUserFromText("3;ana;Pop"));
    }


    private static void testeazaValidator(Validator<User> v, User u, String tip) {
        try {
            v.validate(u);
            System.out.println(tip + ": Validat cu succes");
        } catch (ValidationException e) {
            System.out.println(tip + " -> Eroare: " + e.getMessage());
        }
    }




    /**
     * Builds a small social network in memory: 6 users and 5 friendships
     * (Ana 3 friends, Mihai 2, Ioana 2, Ion 2, Irina 1, Dan 0)
     *
     * @return an in-memory repository with the demo users
     */
    static Repository<Long, User> demoNetwork() {
        Repository<Long, User> repo = new InMemoryRepository<>(new UserValidator());
        String[] lines = {"1;Ana;Pop", "2;Mihai;Ionescu", "3;Ioana;Marin", "4;Ion;Pop", "5;Irina;Pop", "6;Dan;Matei"};
        for (String line : lines)
            repo.save(getUserFromText(line));

        long[][] friendships = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {4, 5}};
        for (long[] p : friendships) {
            User a = repo.findOne(p[0]);
            User b = repo.findOne(p[1]);
            a.getFriends().add(b);
            b.getFriends().add(a);
        }
        return repo;
    }

    // ---------------- Requirement 1- Valid User ----------------

    /**
     * builds users from text lines (id;firstName;lastName), validates them
     * and prints the result; invalid data does not stop the program
     */
    static void requirement1() {
        System.out.println("=== Requirement 1 ===");
        Validator<User> validator = new UserValidator();

        // Data comes as text, like from a text file: id;firstName;lastName
        String[] lines = {
                "1;Ana;Pop",
                "-2;;ionescu",     // 3 validation errors
                "12b;Mihai;Pop",   // id not number -> NumberFormatException
                "3;Ion;"           // missing last name at the end -> see split(";", -1)
        };

        for (String line : lines) {
            try {
                User u = getUserFromText(line);
                validator.validate(u);
                System.out.println("VALID:   " + u);
            } catch (ValidationException e) {
                System.out.println("INVALID: [" + line + "] -> " + e.getMessage());
                if (e.getCause() != null)
                    System.out.println("         Cause: " + e.getCause());
            }
        }
        System.out.println("The app continues after validation.");
    }

    /**
     * creates a user from a text line; the NumberFormatException thrown by
     * Long.parseLong is translated into a ValidationException, keeping the
     * original exception as cause (exception chaining)
     *
     * @param line - text line with the format id;firstName;lastName
     * @return the user created from the given line (not validated yet)
     * @throws ValidationException if the id is not numeric
     */
    static User getUserFromText(String line) {
        // Use -1 as the limit to preserve trailing empty fields, ensuring that
        // empty values at the end of the line are not discarded during splitting.
        String[] fields = line.split(";", -1);
        try {
            User u = new User(fields[1], fields[2]);
            u.setId(Long.parseLong(fields[0]));
            return u;
        } catch (NumberFormatException e) {
            throw new ValidationException("The id '" + fields[0] + "' is not a number", e);
        }
    }

    // ---------------- Requirement 2. In memory repository ----------------

    /**
     * saves the same users in two repositories that use different validation
     * strategies; the exceptions thrown by the validator propagate through
     * the repository and are handled here, in the caller
     */
    static void requirement2() {
        System.out.println("\n=== Requirement 2 ===");
        // Strategy: same context (InMemoryRepository), different validation strategies
        Repository<Long, User> repo = new InMemoryRepository<>(new UserValidator());
        Repository<Long, User> repoStrict = new InMemoryRepository<>(new UserValidatorStrict());

        User ana = getUserFromText("1;Ana;Pop");
        User io = getUserFromText("2;Io;Pop");          // valid normal, valid strict
        User x = getUserFromText("3;X;Pop");            // valid normal, invalid strict
        User anaDublura = getUserFromText("1;Ana;Pop"); // same id

        System.out.println("-- repo (UserValidator)");
        save(repo, ana);
        save(repo, io);
        save(repo, x);
        save(repo, anaDublura);
        save(repo, null);

        System.out.println("-- repoStrict (UserValidatorStrict)");
        save(repoStrict, ana);
        save(repoStrict, x);

        System.out.println("-- findOne / findAll");
        try {
            System.out.println("findOne(1): " + repo.findOne(1L));
            System.out.println("findOne(99): " + repo.findOne(99L));
            System.out.println("findOne(null): " + repo.findOne(null));
            System.out.println("could not arrive here");
        } catch (IllegalArgumentException e) {
            System.out.println("Error findOne: " + e.getMessage());
        }
        System.out.println("findAll: " + repo.findAll());
    }

    /**
     * saves an entity and reports the result; ValidationException (thrown by
     * the validator) and IllegalArgumentException (thrown by the repository)
     * propagate from the repository and are caught here
     *
     * @param repo   - the repository where the user is saved
     * @param entity - the user to be saved (may be null)
     */
    static void save(Repository<Long, User> repo, User entity) {
        try {
            User result = repo.save(entity);
            if (result == null)
                System.out.println("Saved:  " + entity);
            else
                System.out.println("There is:  " + result + " (duplicated id)");
        } catch (ValidationException | IllegalArgumentException e) {
            System.out.println("Error:  " + e.getClass().getSimpleName() + " -> " + e.getMessage());
        } finally {
            System.out.println("  (finally: save operation is done)");
        }
    }

    // ---------------- Requirement 3. File Repository----------------

    /**
     * loads the users from a text file, saves new users (the valid ones reach
     * the file) and reopens the file with a new repository to show that the
     * data persisted
     */
    static void requirement3() {
        System.out.println("\n=== Requirement3 ===");
        String file = "data/users.txt";
        Repository<Long, User> repo = new UserFileRepository(new UserValidator(), file);
        System.out.println("Loaded from file: " + repo.findAll());

        save(repo, getUserFromText("4;Ion;Pop"));
        save(repo, getUserFromText("5;;popescu"));   // invalid

        //restart the app: new repo, over same file
        Repository<Long, User> repoDupaRepornire = new UserFileRepository(new UserValidator(), file);
        System.out.println("After restart:      " + repoDupaRepornire.findAll());

        // file not found -> empty repository, program continues
        Repository<Long, User> repoGol = new UserFileRepository(new UserValidator(), "data/inexistent.txt");
        System.out.println("File not found:   " + repoGol.findAll());
    }

    static void requirement4(){
        System.out.println("\n=== Requirement4 ===");
        Properties props = loadProperties("config.properties");
        RepositoryFactory factory = new RepositoryFactory(props);

        Repository<Long, User> repo = factory.createUserRepository(new UserValidator());
        System.out.println("Created repo:"+repo.getClass().getSimpleName());
        System.out.println("Find all:"+repo.findAll());
    }

    static Properties loadProperties(String resource){
        Properties prop = new Properties();
        try(InputStream in = Main.class.getResourceAsStream(resource)){//need to mark the folder as resource root
        //try(InputStream in = new FileInputStream(resource)){
            if(in == null)
                throw new RuntimeException("There is no resource: " + resource);
            prop.load(in);
        } catch (IOException e) {
            throw new RuntimeException("Error while reading the resource "+e);
        }
        return prop;
    }
}
