<?php

/**
 * This field handler aggregates operations that can be done on a quiz
 * under a single field providing a more flexible way to present them in a view
 */
class quiz_handler_quiz_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['quiz_id'] = 'quiz_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('quiz', 'admin/content/quizs/quiz', array($this->get_value($values, 'quiz_id')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}