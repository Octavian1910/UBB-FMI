package domain.validator;

/**
 * Strategy interface defining the contract for entity validation.
 *
 * @param <T> the type of entity to validate
 */
public interface Validator<T> {

    /**
     * Validates the specified entity against domain rules.
     *
     * @param entity the entity instance to validate
     * @throws ValidationException if the entity violates domain validation rules
     */
    void validate(T entity);
}