package domain;

/**
 * Generic interface representing an entity uniquely identified by an ID.
 *
 * @param <ID> the type of the entity's identifier (e.g., Integer, String, Long)
 */
public interface Entity<ID> {
    ID getId();
}