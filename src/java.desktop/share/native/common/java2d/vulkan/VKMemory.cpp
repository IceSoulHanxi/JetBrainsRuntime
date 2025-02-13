/*
 * Copyright (c) 2023, Oracle and/or its affiliates. All rights reserved.
 * Copyright (c) 2023, JetBrains s.r.o.. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#define VMA_IMPLEMENTATION
#include "VKMemory.h"

void VKMemory::init(vk::Instance instance, const vk::raii::PhysicalDevice& physicalDevice,
                    const vk::raii::Device& device, uint32_t apiVersion, bool extMemoryBudget) {
    vma::VulkanFunctions functions = vma::functionsFromDispatcher(physicalDevice.getDispatcher(), device.getDispatcher());
    vma::AllocatorCreateInfo createInfo {};
    createInfo.instance = instance;
    createInfo.physicalDevice = *physicalDevice;
    createInfo.device = *device;
    createInfo.pVulkanFunctions = &functions;
    createInfo.vulkanApiVersion = apiVersion;
    if (extMemoryBudget) {
        createInfo.flags |= vma::AllocatorCreateFlagBits::eExtMemoryBudget;
    }
    _allocator = vma::createAllocatorUnique(createInfo);
    *((vma::Allocator*) this) = *_allocator;
}

VKBuffer VKMemory::allocateBuffer(uint32_t size, vk::BufferUsageFlags usage,
                                vma::AllocationCreateFlags flags, vma::MemoryUsage memoryUsage) {
    VKBuffer b = nullptr;
    auto pair = createBufferUnique(vk::BufferCreateInfo {
            {}, size, usage, vk::SharingMode::eExclusive, {}
    }, vma::AllocationCreateInfo {
            flags,
            memoryUsage, {}, {}, (uint32_t) -1
    }, b._allocationInfo);
    b._buffer = std::move(pair.first);
    b._allocation = std::move(pair.second);
    b._size = size;
    return b;
}
