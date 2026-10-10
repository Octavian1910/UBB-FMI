import factory.Strategy;

import java.time.LocalDateTime;

public class Main {

    public static void main(String[] args) {

        Strategy strategy =
                Strategy.valueOf(args[0].toUpperCase());

        // runner de bază
        TaskRunner runner =
                new StrategyTaskRunner(strategy);

        // primul decorator
        runner =
                new DelayTaskRunner(runner);

        // al doilea decorator
        runner =
                new PrinterTaskRunner(runner);

        MessageTask[] tasks = new MessageTask[5];

        tasks[0] = new MessageTask(
                "1", "Feedback lab1",
                "Ai obtinut 9.60",
                "Gigi", "Ana",
                LocalDateTime.of(2018, 9, 27, 9, 29)
        );

        tasks[1] = new MessageTask(
                "2", "Feedback lab2",
                "Ai obtinut 10",
                "Gigi", "Ana",
                LocalDateTime.of(2018, 9, 28, 10, 30)
        );

        tasks[2] = new MessageTask(
                "3", "Feedback lab3",
                "Ai obtinut 8.50",
                "Gigi", "Ana",
                LocalDateTime.of(2018, 10, 1, 12, 15)
        );

        tasks[3] = new MessageTask(
                "4", "Feedback lab4",
                "Ai obtinut 9",
                "Gigi", "Ana",
                LocalDateTime.of(2018, 10, 3, 14, 20)
        );

        tasks[4] = new MessageTask(
                "5", "Feedback lab5",
                "Ai obtinut 10",
                "Gigi", "Ana",
                LocalDateTime.of(2018, 10, 5, 16, 45)
        );

        for (MessageTask task : tasks) {
            runner.addTask(task);
        }

        runner.executeAll();
    }
}