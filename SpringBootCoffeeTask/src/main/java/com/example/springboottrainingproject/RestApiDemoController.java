package com.example.springboottrainingproject;


import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.awt.desktop.OpenFilesEvent;
import java.util.LinkedList;
import java.util.List;
import java.util.Optional;

// является совмещением аннотаций @Controller & @ResponseBody
// т.е. они отвечают за ( представления будут визуализироваться в виде
// веб-страницы, отображаемой сервером. ; возвращает все тело ответа на запрос сервера)
@RestController
public class RestApiDemoController {
    private CoffeeRepository coffees_;
    //private List<Coffee> coffees = new LinkedList<>();
    // конструктор контроллера, который инициализирует интерфейсную переменную
    // бд и сохраняет список в неё
    RestApiDemoController(CoffeeRepository coffeeRepository)
    {
        this.coffees_ = coffeeRepository;
        this.coffees_.saveAll(List.of(new Coffee("Kapuchino")
                , new Coffee("Americano")
                , new Coffee("Latte")));
    }

    /*public RestApiDemoController() {
        coffees.addAll(List.of(new Coffee("Kapuchino")
                , new Coffee("Americano")
                , new Coffee("Latte")));
    }*/

    // связывать веб-запросы с методами контроллера
    // value - спецификация пути , второй параметр тип запроса
    //@RequestMapping(value = "/coffees", method = RequestMethod.GET)
    @GetMapping
    Iterable<Coffee> getCoffees() {
        // return coffees;
        return coffees_.findAll();
    }

    // Извлечение одного элемента; есть ли данный элемент в коллекции по данному пути
    // Извлечение данных
    //@GetMapping(value = "/coffees/{id}")
    @GetMapping("/{id}")
    Optional<Coffee> getCoffeeById(@PathVariable String id) {
        /*for(var a : coffees)
        {
            if(a.getName().equals(id)) return Optional.of(a);
        }
        return Optional.empty();*/
        return coffees_.findById(id);
    }

    // получение данных, передача описания
    @PostMapping("/coffees")
    Coffee postCoffee(@RequestBody Coffee coffee) {
        //coffees.add(coffee);
        return coffees_.save(coffee);
    }

    // модификация ресурсов
    // в отличие от остальных методов необходимо указывать код возврата: ResponseEntity
    @PutMapping("/{id}")
    ResponseEntity<Coffee> putCoffee(@PathVariable String id,
                                     @RequestBody Coffee coffee) {
        /*int coffeeIndex = -1;
        for (Coffee c: coffees) {
            if (c.getId().equals(id)) {
                coffeeIndex = coffees.indexOf(c);
                coffees.set(coffeeIndex, coffee);
            }
        }
        return (coffeeIndex == -1) ?
                new ResponseEntity<>(postCoffee(coffee), HttpStatus.CREATED) :
                new ResponseEntity<>(coffee, HttpStatus.OK);*/
        return (!coffees_.existsById(id))
                ? new ResponseEntity<>(postCoffee(coffee), HttpStatus.CREATED)
                : new ResponseEntity<>(coffee, HttpStatus.OK);
    }

    // удаление ресурсов
    @DeleteMapping("/coffees/{id}")
    void deleteCoffee(@PathVariable String id) {
        //coffees.removeIf(c -> c.getId().equals(id));
        coffees_.deleteById(id);
    }

}
