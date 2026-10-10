import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MessageTask extends Task {

    private String mesaj;
    private String from;
    private String to;
    private LocalDateTime date;

    public MessageTask(String taskID, String description,
                       String mesaj, String from, String to,
                       LocalDateTime date) {

        super(taskID, description);

        this.mesaj = mesaj;
        this.from = from;
        this.to = to;
        this.date = date;
    }

    @Override
    public void execute() {
        System.out.println("Mesaj trimis de la " + from + " catre " + to);
    }

    @Override
    public String toString() {
        DateTimeFormatter formatter =
                DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");

        return super.toString()
                + "|message=" + mesaj
                + "|from=" + from
                + "|to=" + to
                + "|date=" + date.format(formatter);
    }
}