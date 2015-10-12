#pragma once

#include "macro.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

struct producer_ops {
  METHOD0(bool, init);
  METHOD0(void, destroy);

  METHOD0(uint32_t, get_epoll_event);
  METHOD0(int, get_fd);
  METHOD(ssize_t, produce, void *buf, size_t count, bool *eof);
  METHOD(ssize_t, signal, bool *eof);
};

struct producer {
  OBJECT(struct producer_ops);
};

struct consumer_ops {
  METHOD0(bool, init);
  METHOD0(void, destroy);

  METHOD0(uint32_t, get_epoll_event);
  METHOD0(int, get_fd);
  METHOD(ssize_t, consume, void *buf, size_t count);
  METHOD0(ssize_t, signal);
};

struct consumer {
  OBJECT(struct consumer_ops);
};

bool is_empty_producer(struct producer *producer);
bool is_empty_consumer(struct consumer *consumer);
