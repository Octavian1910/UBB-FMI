package repository;

import domain.User;

import java.util.SplittableRandom;

public class UserFileRepository extends AbstractFileRepository<Integer, User> {

    public UserFileRepository(String filePath) {
        super(filePath);
    }

    @Override
    protected User extractEntity(String line) {
        String[] fields = line.split(";", -1);
        if (fields.length != 3) {
            throw new RepositoryException("Invalid line format (expected 3 tokens):" + line);
        }try {
            int id = Integer.parseInt(fields[0].trim());
            String firstName = fields[1].trim();
            String lastName = fields[2].trim();
            return new User(id, firstName, lastName);
        }catch (NumberFormatException e){
            throw new RepositoryException("Invalid user ID number: " + line,e);
        }
    }

    @Override
    protected String createEntityAsString(User user) {
        return user.getId() + ";" + user.getFirstName() + ";" + user.getLastName();
    }
}
