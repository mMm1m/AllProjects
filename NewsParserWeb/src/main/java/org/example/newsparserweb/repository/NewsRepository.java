package org.example.newsparserweb.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import org.example.newsparserweb.model.News;

@Repository
public interface NewsRepository extends JpaRepository<News, Long>{

}