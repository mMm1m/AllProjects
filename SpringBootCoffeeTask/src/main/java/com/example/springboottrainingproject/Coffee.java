package com.example.springboottrainingproject;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;

import java.util.UUID;
// сохраняемая сущность
@Entity
public class Coffee {
    @Id
    private String id;
    private String name;
    public Coffee(String id, String name)
    {
        this.id = id;
        this.name = name;
    }

    public Coffee(String name)
    {
        this(UUID.randomUUID().toString(), name);
    }
    // для создания объектов для строк бд
    public Coffee() {

    }

    public String getName()
    {
        return name;
    }

    public String getId()
    {
        return id;
    }

    public void setName(String str)
    {
        this.name = name;
    }

    public void setId(String id)
    {
        this.id = id;
    }
}
