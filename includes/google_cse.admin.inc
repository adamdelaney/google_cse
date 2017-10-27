<?php

/**
 * @file
 *
 * Administrative form functions for the Google Custom Search Engine.
 */

/**
 * Page callback: Google Custom Search Engine configuration form.
 *
 * @see google_cse_menu()
 */
function google_cse_config_form($form, &$form_state) {
  $form['markup'] = array(
    '#type' => 'markup',
    '#markup' => t('<p>These settings allows you to customize the Google Custom Search Engine.</p>'),
  );

  $form['google_cse_engine_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Search Engine ID'),
    '#default_value' => variable_get('google_cse_engine_id'),
    '#description' => t('Enter the CSE Engine ID.'),
    '#size' => 60,
    '#required' => TRUE,
  );

  $form['google_cse_scope'] = array(
    '#type' => 'checkbox',
    '#title' => t('Limit Custom Search to this Site'),
    '#default_value' => variable_get('google_cse_scope'),
    '#description' => t('If checked, the Google Custom Search will be scoped to this site only. If you are using a CSE ID that includes multiple sites in it, you will likely want to uncheck this.'),
    '#size' => 60,
  );

  $form['google_cse_render_top'] = array(
    '#type' => 'checkbox',
    '#title' => t('Print the search form in region-top.'),
    '#default_value' => variable_get('google_cse_render_top'),
    '#description' => t('If checked, the Google Custom Search form will be printed in region-top.'),
    '#size' => 60,
  );

  $form['google_cse_expose_block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Expose the search form as a block.'),
    '#default_value' => variable_get('google_cse_expose_block'),
    '#description' => t('If checked, the Google Custom Search form will be available as a block and can be configured at: /admin/structure/block.'),
    '#size' => 60,
  );

  return system_settings_form($form);
}
