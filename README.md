# clahe_ros

Implements CLAHE in a ros node

## Subscribers

`/image`: `sensor_msgs/Image`

## Publishers

`/equalized_image`: `sensor_msgs/Image`

## Parameters

| Name | Type | Default | Description |
| ----- | ----- | ----- | ----- |
| clahe_clip_limit | `double` | 2 | Number of pixels used to clip the CDF for histogram equalization |
| clahe_grid_size | `double` | 6 | clahe_grid_size_ x clahe_grid_size_ pixel neighborhood used |
