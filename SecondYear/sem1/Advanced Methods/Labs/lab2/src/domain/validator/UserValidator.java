package domain.validator;

import domain.User;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class UserValidator implements Validator<User> {

    private record ValidationRule(Predicate<User> predicate, String errorMessage) {
    }

    private final List<ValidationRule> rules = new ArrayList<>();

    public UserValidator() {
        rules.add(new ValidationRule(user -> user.getId() != null && user.getId() > 0, "User ID must be positive!"));
        rules.add(new ValidationRule(user -> user.getFirstName() != null && !user.getFirstName().trim().isEmpty(), "First name cannot be empty!"));
        rules.add(new ValidationRule(user -> user.getFirstName() != null && !user.getFirstName().trim().isEmpty() && Character.isUpperCase(user.getFirstName().trim().charAt(0)), "First name must start with an uppercase letter!"));
        rules.add(new ValidationRule(user -> user.getLastName() != null && !user.getLastName().trim().isEmpty(), "Last name cannot be empty!"));
        rules.add(new ValidationRule(user -> user.getLastName() != null && !user.getLastName().trim().isEmpty() && Character.isUpperCase(user.getLastName().trim().charAt(0)), "Last name must start with an uppercase letter!"));
    }

    @Override
    public void validate(User user) {
        if (user == null) {
            throw new ValidationException("User cannot be null!");
        }

        List<String> errors = rules.stream()
                .filter(rule -> !rule.predicate().test(user))
                .map(rule -> rule.errorMessage()).toList();

        if (!errors.isEmpty()) {
            throw new ValidationException(String.join("\n", errors));
        }

    }

}