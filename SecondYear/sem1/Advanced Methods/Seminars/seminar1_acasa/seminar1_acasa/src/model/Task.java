package model;

import java.util.Objects;

public abstract class Task {
    private String taskID;
    private String descriere;

    public Task(String taskID, String descriere) {
        this.taskID = taskID;
        this.descriere = descriere;
    }

    public abstract void execute();

    public String getTaskID() {
        return taskID;
    }

    public String getDescriere() {
        return descriere;
    }

    public void setTaskID(String newTaskID) {
        this.taskID = newTaskID;
    }

    public void setDescriere(String newDescreire) {
        this.descriere = newDescreire;
    }

    @Override
    public String toString() {
        return "id=" + taskID + "|description=" + descriere;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true; //daca au aceeasi referinta
        if (o == null || this.getClass() != o.getClass())
            return false; // daca o este null sau obiectele sunt de tip diferit
        Task task = (Task) o; //facem cast la o sa fie model.Task
        return Objects.equals(taskID, task.taskID) &&
                Objects.equals(descriere, task.descriere);
    }

    @Override
    public int hashCode() {
        return Objects.hash(taskID, descriere);
    }
}
