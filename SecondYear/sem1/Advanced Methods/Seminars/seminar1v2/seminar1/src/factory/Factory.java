
import container.Container;

public interface Factory {
    Container createContainer(factory.Strategy strategy);
}