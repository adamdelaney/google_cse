<?php

/**
 * @file
 *
 * Build and theme the Google Custom Search Engine.
 */

/**
 * Build out the Google Custom Search Engine.
 */
function build_google_cse() {
  $google_cse = array();
  $google_cse['search-bar'] = array(
    '#attributes' => array('id' => array('search-wrapper')),
    '#type' => 'container',
  );
  $google_cse['search-bar']['container'] = array(
    '#attributes' => array('class' => array('container', 'l-container')),
    '#type' => 'container',
  );
  $google_cse['search-bar']['container']['cse-search'] = array(
    '#attributes' => array(
      'id' => array('cse-search'),
      'class' => array('is-visible'),
    ),
    '#type' => 'container',
  );
  $google_cse['search-bar']['container']['cse-search']['search-form'] = drupal_get_form('google_cse_search_form');

  return $google_cse;
}

/**
 * Build out search form for the CSE.
 */
function google_cse_search_form($form, &$form_state) {
  $form = array();
  $form['search-icon'] = array(
    '#markup' => '<i class="fa fa-search" aria-hidden="true"></i>',
  );
  $form['search-terms'] = array(
    '#type' => 'textfield',
    '#title' => t('Search Terms'),
    '#attributes' => array(
      'placeholder' => 'Search this site',
    ),
    '#maxlength' => '256',
    '#size' => '15',
  );
  $form['submit-search'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#name' => 'btnG',
  );
  $form['#action'] = $GLOBALS['base_url'] . '/google-search';

  // Use core search CSS in addition to this module's css. Keep it general in
  // case core search is enabled.
  $form['#attributes']['class'][] = 'search-form';
  $form['#attributes']['class'][] = 'search-google-appliance-search-form';

  return $form;
}

/**
 * Submit handler for full search form.
 */
function google_cse_search_form_submit($form, &$form_state) {
  // Set the redirect.
  $search_query = urlencode($form_state['input']['search-terms']);
  $form_state['redirect'] = url($form['#action'] . '?search=' . $search_query, array('absolute' => FALSE));
}
