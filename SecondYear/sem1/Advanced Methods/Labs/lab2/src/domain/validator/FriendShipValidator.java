package domain.validator;

import domain.FriendShip;

/**
 * Concrete strategy implementing domain validation for {@link FriendShip} entities.
 */
public class FriendShipValidator implements Validator<FriendShip> {

    @Override
    public void validate(FriendShip friendShip) {
        if (friendShip == null) {
            throw new ValidationException("Friendship cannot be null!");
        }

        StringBuilder errors = new StringBuilder();

        if (friendShip.getFirstUserId() <= 0) {
            errors.append("First user ID must be positive! ");
        }
        if (friendShip.getSecondUserId() <= 0) {
            errors.append("Second user ID must be positive! ");
        }
        if (friendShip.getFirstUserId() == friendShip.getSecondUserId()) {
            errors.append("A user cannot be friends with themselves! ");
        }

        if (errors.length() > 0) {
            throw new ValidationException(errors.toString().trim());
        }
    }
}