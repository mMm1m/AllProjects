package com.example.springboottrainingproject;

import org.springframework.data.repository.CrudRepository;

// определяет репозиторий(т.е. интерфейс, являющийся абстракцией б.д.)
// <Coffee, String> - объект и его идентификатор
public interface CoffeeRepository extends CrudRepository<Coffee,String> {
    // автоматический поиск драйвера БД и автоматически создаётся
    // прокси бд
}
