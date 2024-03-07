package ru.mail.polis.homework.generics.bot;

import ru.mail.polis.homework.generics.bot.handler.StateHandler;
import ru.mail.polis.homework.generics.bot.state.State;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class Bot {
    Map<Class<? extends State>, StateHandler<? extends State>> handlerMap;
    /**
     * Конструктор бота, которому на вход подаются хэндлеры состояний.
     * Необходимо как-то сохранить эти хэндлеры так, чтобы потом можно было вызвать нужный хэндлер из метода handleState
     *
     * 1 тугрик
     */
    public Bot(List<StateHandler<? extends State>> handlers) {
        handlerMap = new HashMap<>();
        for(var a : handlers)
        {
            handlerMap.put(a.getHandlingStateClass(), a);
        }
    }

    /**
     * Вызывает хэндлер, предназначенный для переданного State
     *
     * 1 тугрик
     */
    public void handleState(State state) {
        handlerMap.get(state.getClass()).handle();
    }
}