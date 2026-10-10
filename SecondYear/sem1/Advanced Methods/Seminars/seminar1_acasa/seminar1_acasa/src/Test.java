import factory.Strategy;
import model.MessageTask;
import model.SortingStrategy;
import model.SortingTask;
import model.Task;
import runner.DelayTaskRunner;
import runner.PrinterTaskRunner;
import runner.StrategyTaskRunner;
import runner.TaskRunner;

import java.time.LocalDateTime;

public class Test {

    private static MessageTask[] createTasks() {
        MessageTask[] tasks = new MessageTask[5];
        tasks[0] = new MessageTask("1", "Feedback lab1", "Ai obtinut 9.6", "Gigi", "Ana", LocalDateTime.of(2024, 10, 15, 9, 20));
        tasks[1] = new MessageTask("2", "Feedback lab2", "Ai obtinut 8.2", "Andrei", "Ioana", LocalDateTime.of(2026, 12, 14, 8, 59));
        tasks[2] = new MessageTask("3", "Feedback lab3", "Ai obtinut 9.0", "Octa", "Alex", LocalDateTime.of(2025, 9, 10, 7, 14));
        tasks[3] = new MessageTask("4", "Feedback lab4", "Ai obtinut 6.5", "Stef", "Mihai", LocalDateTime.of(2022, 8, 5, 6, 13));
        tasks[4] = new MessageTask("5", "Feedback lab5", "Ai obtinut 6.6", "Luca", "Darius", LocalDateTime.of(2021, 1, 1, 5, 12));
        return tasks;
    }

    private static void messageTaskTest() {
        MessageTask[] tasks = createTasks();
        for (MessageTask task : tasks) {
            System.out.println(task);
        }
    }

    private static void taskRunnerTest(Strategy strategy) {
        StrategyTaskRunner runner = new StrategyTaskRunner(strategy);
        MessageTask[] tasks = createTasks();
        for (MessageTask task : tasks)
            runner.addTask(task);

        runner.executeAll();
        System.out.println();
    }

    private static void testDecorators(Strategy strategy) {
        TaskRunner runner = new StrategyTaskRunner(strategy);
        TaskRunner printerRunner = new PrinterTaskRunner(runner);
        TaskRunner delayRunner = new DelayTaskRunner(printerRunner);

        MessageTask[] tasks = createTasks();
        for (MessageTask task : tasks){
            delayRunner.addTask(task);
        }
        delayRunner.executeAll();
    }

    private static void testSortingTask()
    {
        int[] array1 = {5, 2, 9, 1, 5, 6};
        int[] array2 = {12, 4, 7, 3, 1, 9};

        Task task1 = new SortingTask("10", "Bubble sort task", array1, SortingStrategy.BUBBLE_SORT);
        Task task2 = new SortingTask("11", "Quick sort task", array2, SortingStrategy.QUICK_SORT);

        TaskRunner runner = new StrategyTaskRunner(Strategy.FIFO);
        runner.addTask(task1);
        runner.addTask(task2);

        runner.executeAll();
    }

    public static void runAll(String[] args) {
        messageTaskTest();
        taskRunnerTest(Strategy.FIFO);
        taskRunnerTest(Strategy.LIFO);
        testDecorators(Strategy.FIFO);
        testDecorators(Strategy.LIFO);
        testSortingTask();
        System.out.println("All tests have passed!");
    }
}
