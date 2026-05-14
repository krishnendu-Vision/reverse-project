// Copyright (c) 2026 Robin <robin413@protonmail.com>
// SPDX-License-Identifier: MIT

//go:build !linux

package gpm

import "github.com/gdamore/tcell/v2"

// Client is an empty stub on non-Linux platforms.
type Client struct{}

// IsGPMAvailable always returns false on non-Linux platforms.
func IsGPMAvailable() bool { return false }

// Connect always returns nil on non-Linux platforms.
func Connect(_ func(tcell.Event)) (*Client, error) { return nil, nil }

// Start is a no-op on non-Linux platforms.
func (c *Client) Start() {}

// Stop is a no-op on non-Linux platforms.
func (c *Client) Stop() {}
