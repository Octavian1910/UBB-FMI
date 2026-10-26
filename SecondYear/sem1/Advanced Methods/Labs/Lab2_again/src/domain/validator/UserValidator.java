package domain.validator;

import domain.User;

public class UserValidator implements Validator<User> {

    @Override
    public void validate(User user) {
        if (user == null)
            throw new ValidationException("User cannot be null! ");

        StringBuilder errors = new StringBuilder();
        if (user.getId() <= 0){
            errors.append("User ID must be positive! ");
        }

        if (user.getFirstName() == null || user.getFirstName().trim().isEmpty()){
            errors.append("First name cannot be empty! ");
        }

        if (user.getLastName() == null || user.getLastName().trim().isEmpty()){
            errors.append("Last name cannot be empty! ");
        }

        if (!errors.isEmpty()){
            throw new ValidationException(errors.toString().trim());
        }
    }
}
