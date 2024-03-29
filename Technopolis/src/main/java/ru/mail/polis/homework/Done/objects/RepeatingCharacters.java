package ru.mail.polis.homework.objects;


import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.TreeMap;

/**
 * Нужно найти символ, который встречается подряд в строке чаще всего, и указать количество повторений.
 * Если более одного символа с максимальным значением, то нужно вернуть тот символ,
 * который первый встречается в строчке
 * Если строка пустая или null, то вернуть null
 * Пример abbasbdlbdbfklsssbb -> (s, 3)
 * 4 тугрика
 */
public class RepeatingCharacters {

    public static Pair<Character, Integer> getMaxRepeatingCharacters(String str) {
        if(str == null || str.isEmpty()) return null;
        if(str.length() == 1) return new Pair(str.charAt(0), 1);
        else
        {
            int local_max = 1, max = 1;
            char tmp = str.charAt(0);
            for(int i = 1; i < str.length(); ++i)
            {
                if(str.charAt(i) == str.charAt(i-1)) ++local_max;
                else local_max = 1;
                if(local_max > max)
                {
                    max = local_max;
                    tmp = str.charAt(i);
                }
            }
            return new Pair(tmp, max);
        }
    }

    public static class Pair<T, V> {
        private final T first;
        private final V second;

        public Pair(T first, V second) {
            this.first = first;
            this.second = second;
        }

        public T getFirst() {
            return first;
        }

        public V getSecond() {
            return second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

    }
}
