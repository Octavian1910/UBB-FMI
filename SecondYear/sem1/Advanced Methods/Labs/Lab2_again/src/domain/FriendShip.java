package domain;

import java.time.LocalDateTime;

public class FriendShip implements Entity<String> {
    private final int firstUserId;
    private final int secondUserId;
    private final LocalDateTime date;

    public FriendShip(int firstUserId, int secondUserId, LocalDateTime date) {
        this.firstUserId = Math.min(firstUserId, secondUserId);
        this.secondUserId = Math.max(firstUserId, secondUserId);
        this.date = date;
    }

    public FriendShip(int firstUserId, int secondUserId) {
        this.firstUserId = Math.min(firstUserId, secondUserId);
        this.secondUserId = Math.max(firstUserId, secondUserId);
        this.date = LocalDateTime.now();
    }

    public LocalDateTime getDate() {
        return date;
    }

    @Override
    public String getId() {
        return firstUserId + "-" + secondUserId;
    }

    public int getSecondUserId() {
        return secondUserId;
    }

    public int getFirstUserId() {
        return firstUserId;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        FriendShip that = (FriendShip) obj;
        return firstUserId == that.firstUserId && secondUserId == that.secondUserId;
    }

    @Override
    public String toString() {
        return "FriendShip{firstUserId=" + firstUserId +
                ", secondUserId=" + secondUserId +
                ", date=" + date + "}";
    }
}
