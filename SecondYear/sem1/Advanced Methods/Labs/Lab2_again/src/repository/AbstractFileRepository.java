package repository;

import domain.Entity;

import java.io.*;
import java.util.Optional;

public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID, E> {
    protected final String fileName;

    protected abstract E extractEntity(String line);

    protected abstract String createEntityAsString(E entity);

    public AbstractFileRepository(String fileName) {
        super();
        if (fileName == null || fileName.trim().isEmpty()) {
            throw new IllegalArgumentException("File name cannot be null or empty!");
        }
        this.fileName = fileName;
        loadFromFile();
    }

    private void loadFromFile() {
        File file = new File(fileName);
        if (!file.exists()) {
            return;
        }
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            int lineNumber = 0;
            while ((line = br.readLine()) != null) {
                lineNumber++;
                if (line.trim().isEmpty()) {
                    continue;
                }
                try {
                    E entity = extractEntity(line);
                    super.add(entity);
                } catch (RepositoryException e) {
                    System.err.println("Skipping corrupted line " + lineNumber + " in " + fileName + ": " + e.getMessage());
                }
            }

        } catch (IOException e) {
            throw new RepositoryException("Error reading from file: " + fileName + " in " + fileName + ": " + e.getMessage());
        }
    }

    private void writeToFile() {
        File file = new File(fileName);
        File parent = file.getParentFile();
        if (parent != null && !parent.exists()) {
            parent.mkdirs();
        }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(file))) {
            for (E entity : entities.values()) {
                bw.write(createEntityAsString(entity));
            }
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
        if (removed.isPresent()){
            writeToFile();
        }
        return removed;
    }

    @Override
    public Optional<E> update(E entity) {
        Optional<E> updated = super.update(entity);
        if (updated.isEmpty()){
            writeToFile();
        }
        return updated; //optional sau contine obiectul care nu a fost gasit deci nu s a putut modifica
    }
}
