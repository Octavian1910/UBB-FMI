import java.util.Objects;

public abstract class Task {
    private String taskID;
    private String description;

    public Task(String taskID, String description) {
        this.taskID = taskID;
        this.description = description;
    }

    public abstract void execute();

    public String getTaskID() {
        return taskID;
    }

    public String getDescription() {
        return description;
    }

    @Override
    public String toString() {
        return "id=" + taskID + "|description=" + description;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;

        if (!(o instanceof Task))
            return false;

        Task task = (Task) o;

        return taskID.equals(task.taskID);
    }

    @Override
    public int hashCode() {
        return Objects.hash(taskID);
    }
}