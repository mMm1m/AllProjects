package com.example.springboottools;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/greeting")
public class GreetingController {
    // для включения параметров конфигурации(application.properties) в код
    // аннотация @Value
    @Value("${greeting_name: NAME}")
    private String name;

    @Value("${greeting_coffee: ${greeting_name: NAME} is drinking coffee}")
    private String coffee;

    @GetMapping
    public String greeting()
    {
        return name;
    }

    @GetMapping("/coffees")
    public String getCoffee()
    {
        return coffee;
    }
}
