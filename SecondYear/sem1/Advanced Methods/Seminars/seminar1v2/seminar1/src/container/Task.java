package container;

public abstract class Task {
    private String taskId;
    private String description;

    public Task(String taskId, String description) {
        this.taskId = taskId;
        this.description = description;
    }

    public abstract void execute();

    @Override
    public String toString() {
        return "id=" + taskId + "|description=" + description;
    }

    @Override
    public boolean equals(Object o) {
     if (this == o)
         return true;

     if (!(o instanceof Task))
         return false;

     Task task = (Task) o;
     return taskId.equals(task.taskId);
    }

    @Override
    public int hashCode()
    {
        return taskId.hashCode();
    }
}
