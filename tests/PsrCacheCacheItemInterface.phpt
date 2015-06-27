--TEST--
Psr\Cache\CacheItemInterface
--SKIPIF--
<?php if( !extension_loaded('psr') ) die('skip '); ?>
--FILE--
<?php
include __DIR__ . '/SampleCacheItem.inc';
var_dump(interface_exists('\\Psr\\Cache\\CacheItemInterface', false));
var_dump(class_implements('SampleCacheItem', false));
$cacheItem = new SampleCacheItem();
$cacheItem->getKey();
$cacheItem->get();
$cacheItem->set('test set');
$cacheItem->isHit();
$cacheItem->exists();
$cacheItem->expiresAt(1435364259);
$cacheItem->expiresAfter(1435364259);
$cacheItem->getExpiration();
--EXPECT--
bool(true)
array(1) {
  ["Psr\Cache\CacheItemInterface"]=>
  string(28) "Psr\Cache\CacheItemInterface"
}
string(23) "SampleCacheItem::getKey"
string(20) "SampleCacheItem::get"
string(20) "SampleCacheItem::set"
string(8) "test set"
string(22) "SampleCacheItem::isHit"
string(23) "SampleCacheItem::exists"
string(26) "SampleCacheItem::expiresAt"
int(1435364259)
string(29) "SampleCacheItem::expiresAfter"
int(1435364259)
string(30) "SampleCacheItem::getExpiration"

