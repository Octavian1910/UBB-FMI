public class ComplexParser {
    public static Complex parse(String text) {
        if (text == null || text.trim().isEmpty()) {
            return null;
        }

        text = text.trim();
        int operatorIndex = -1;
        for (int i = 1; i < text.length(); i++) {
            char ch = text.charAt(i);
            if (ch == '+' || ch == '-') {
                operatorIndex = i;
                break;
            }
        }

        if (operatorIndex == -1 || text.charAt(text.length() - 1) != 'i') {
            return null;
        }
        try {
            String realStr = text.substring(0, operatorIndex);
            String imStr = text.substring(operatorIndex);

            imStr = imStr.replace("*i", "").replace("i", "");

            double real = Double.parseDouble(realStr);
            double imaginary;
            if (imStr.equals("+")) {
                imaginary = 1;
            } else if (imStr.equals("-")) {
                imaginary = -1;
            } else {
                imaginary = Double.parseDouble(imStr);
            }

            return new Complex(real, imaginary);
        } catch (NumberFormatException e) {
            return null;
        }
    }
}
