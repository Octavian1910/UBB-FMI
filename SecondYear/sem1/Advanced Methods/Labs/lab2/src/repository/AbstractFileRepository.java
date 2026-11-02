package repository;

import domain.Entity;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.Optional;
import java.util.stream.Stream;

/**
 * Abstract generic file repository coordinating file persistence.
 * Implements the Template Method design pattern.
 *
 * @param <ID> the identifier type
 * @param <E>  the entity type
 */
public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID, E> {
    protected final String fileName;

    /**
     * Constructs the file repository and loads existing data.
     *
     * @param fileName file storage path
     * @throws IllegalArgumentException if fileName is null or empty
     */
    public AbstractFileRepository(String fileName) {
        super();
        if (fileName == null || fileName.trim().isEmpty()) {
            throw new IllegalArgumentException("File name cannot be null or empty!");
        }
        this.fileName = fileName;
        loadFromFile();
    }

    /**
     * Reads all entities from the text file into memory.
     * Corrupted lines are reported and skipped.
     */
    private void loadFromFile() {
        Path path = Path.of(fileName);
        if (!Files.exists(path)) {
            return;
        }

        try (Stream<String> lines = Files.lines(path)) {
            lines.filter(line -> !line.isBlank())
                    .forEach(line -> {
                        try {
                            E entity = extractEntity(line);
                            super.add(entity);
                        } catch (RepositoryException e) {
                            System.err.println("Skipping corrupted line in " + fileName + ": " + e.getMessage());
                        }
                    });
        } catch (IOException e) {
            throw new RepositoryException("Error reading from file: " + fileName, e);
        }
    }

    /**
     * Parses a string line from the file into an entity instance.
     *
     * @param line raw text line
     * @return the extracted entity
     * @throws RepositoryException if tokenization or parsing fails
     */
    protected abstract E extractEntity(String line);

    /**
     * Formats an entity into its text line representation.
     *
     * @param entity the entity to format
     * @return serialized text representation
     */
    protected abstract String createEntityAsString(E entity);

    /**
     * Rewrites all in-memory entities back to the text file.
     */
    private void writeToFile() {
        Path path = Path.of(fileName);
        Path parent = path.getParent();
        if (parent != null && !Files.exists(parent)) {
            try {
                Files.createDirectories(parent);
            } catch (IOException e) {
                throw new RepositoryException("Could not create directories for: " + fileName, e);
            }
        }

        List<String> lines = entities.values().stream()
                .map(entity -> createEntityAsString(entity))
                .toList();

        try {
            Files.write(path, lines);
        } catch (IOException e) {
            throw new RepositoryException("Error writing to file: " + fileName, e);
        }
    }

    @Override
    public void add(E entity) {
        super.add(entity);
        writeToFile();
    }

    @Override
    public Optional<E> remove(ID id) {
        Optional<E> removed = super.remove(id);
        if (removed.isPresent()) {
            writeToFile();
        }
        return removed;
    }

    @Override
    public Optional<E> update(E entity) {
        Optional<E> updated = super.update(entity);
        if (updated.isEmpty()) {
            writeToFile();
        }
        return updated;
    }
}