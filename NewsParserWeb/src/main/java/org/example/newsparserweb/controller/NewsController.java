package org.example.newsparserweb.controller;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import org.example.newsparserweb.model.News;
import org.example.newsparserweb.service.NewsService;

@RestController
public class NewsController {

    @Autowired
    NewsService newsService;

    @GetMapping(value = "/news")
    public List<News> getNews() {
        return newsService.getAllNews();
    }
}