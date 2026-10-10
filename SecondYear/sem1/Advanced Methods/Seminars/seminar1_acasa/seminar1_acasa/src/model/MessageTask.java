package model;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MessageTask extends Task {
    private String mesaj;
    private String from;
    private String to;
    private LocalDateTime date;

    public static final DateTimeFormatter DATE_TIME_FORMATTER = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");

    public MessageTask(String taskID, String descriere, String mesaj, String from, String to, LocalDateTime date) {
        super(taskID, descriere);
        this.mesaj = mesaj;
        this.from = from;
        this.to = to;
        this.date = date;
    }

    @Override
    public void execute() {
        System.out.println(mesaj + " " + date.format(DATE_TIME_FORMATTER));
    }

    @Override
    public String toString() {
        return super.toString() +
                "|message=" + mesaj +
                "|from=" + from +
                "|to=" + to +
                "|date=" + date.format(DATE_TIME_FORMATTER);
    }
}
