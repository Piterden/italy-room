<?php
/**
 * @file
 *   List of localization servers
 *   WARNING!!! Server must include translation of Drupal core modules. It is Default Localization Server.
 *
 */

function l10n_update_config_get_servers(){
  return array(
    'localize.drupal.org' => array(
      'l10n_update_default_server'     => 'localize.drupal.org',
      'l10n_update_default_server_url' => 'http://localize.drupal.org/l10n_server.xml',
      'l10n_update_default_update_url' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%release.%language.po',
      'description' => 'Official translation server',
    ),
    'drupaler.ru' => array(
      'l10n_update_default_server'     => 'drupaler.ru',
      'l10n_update_default_server_url' => 'http://drupaler.ru/files/l10n_packager/l10n_server.xml',
      'l10n_update_default_update_url' => 'http://drupaler.ru/files/l10n_packager/%core/%project/%project-%release.%language.po',
      'description' => 'First Russian translation server',
    ),
    'drupalize.ru' => array(
      'l10n_update_default_server'     => 'drupalize.ru',
      'l10n_update_default_server_url' => 'http://drupalize.ru/sites/default/files/l10n_packager/l10n_server.xml',
      'l10n_update_default_update_url' => 'http://drupalize.ru/sites/default/files/l10n_packager/%core/%project/%project-%release.%language.po',
      'description' => 'Alternative Russian translation server',
    ),
  );
}