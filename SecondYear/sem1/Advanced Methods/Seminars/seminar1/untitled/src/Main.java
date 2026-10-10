import java.time.LocalDateTime;

public class Main {

    public static void main(String[] args) {

        MessageTask[] tasks = new MessageTask[5];

        tasks[0] = new MessageTask(
                "id=1",
                "Feedback lab1",
                "Ai obtinut 9.60",
                "Gigi",
                "Ana",
                LocalDateTime.of(2018, 9, 27, 9, 29)
        );

        tasks[1] = new MessageTask(
                "id=2",
                "Feedback lab2",
                "Ai obtinut 10",
                "Gigi",
                "Ana",
                LocalDateTime.of(2018, 9, 28, 10, 30)
        );

        tasks[2] = new MessageTask(
                "id=3",
                "Feedback lab3",
                "Ai obtinut 8.50",
                "Gigi",
                "Ana",
                LocalDateTime.of(2018, 10, 1, 12, 15)
        );

        tasks[3] = new MessageTask(
                "id=4",
                "Feedback lab4",
                "Ai obtinut 9",
                "Gigi",
                "Ana",
                LocalDateTime.of(2018, 10, 3, 14, 20)
        );

        tasks[4] = new MessageTask(
                "id=5",
                "Feedback lab5",
                "Ai obtinut 10",
                "Gigi",
                "Ana",
                LocalDateTime.of(2018, 10, 5, 16, 45)
        );

        for (MessageTask task : tasks) {
            System.out.println(task);
        }
    }
}