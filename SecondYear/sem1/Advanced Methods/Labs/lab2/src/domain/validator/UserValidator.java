package domain.validator;

import domain.User;

/**
 * Concrete strategy implementing domain validation for {@link User} entities.
 */
public class UserValidator implements Validator<User> {

    @Override
    public void validate(User user) {
        if (user == null) {
            throw new ValidationException("User cannot be null!");
        }

        StringBuilder errors = new StringBuilder();

        if (user.getId() <= 0) {
            errors.append("User ID must be positive! ");
        }
        if (user.getFirstName() == null || user.getFirstName().trim().isEmpty()) {
            errors.append("First name cannot be empty! ");
        } else if (!Character.isUpperCase(user.getFirstName().charAt(0))) {
            errors.append("First name must start with an uppercase letter! ");
        }

        if (user.getLastName() == null || user.getLastName().trim().isEmpty()) {
            errors.append("Last name cannot be empty! ");
        } else if (!Character.isUpperCase(user.getLastName().charAt(0))) {
            errors.append("Last name must start with an uppercase letter! ");
        }

        if (errors.length() > 0) {
            throw new ValidationException(errors.toString().trim());
        }
    }
}