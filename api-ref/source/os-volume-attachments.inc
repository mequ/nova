.. -*- rst -*-
.. needs:body_verification

===================================================================
 Servers with volume attachments (servers, os-volume\_attachments)
===================================================================

Attaches volumes that are created through the volume API to server
instances. Also, lists volume attachments for a server instance, shows
details for a volume attachment, and detaches a volume.

List volume attachments for an instance
=======================================

.. rest_method:: GET /servers/{server_id}/os-volume_attachments

List volume attachments for an instance.

Normal response codes: 200

Error response codes: unauthorized(401), forbidden(403), itemNotFound(404)

Request
-------

.. rest_parameters:: parameters.yaml


  - server_id: server_id_path

Response
--------

.. rest_parameters:: parameters.yaml

  - volumeAttachments: volumeAttachments
  - device: device_resp
  - id: attachment_id_resp
  - serverId: server_id
  - volumeId: volumeId_resp

**Example List volume attachments for an instance: JSON response**

.. literalinclude:: ../../doc/api_samples/os-volumes/list-volume-attachments-resp.json
   :language: javascript

Attach a volume to an instance
==============================

.. rest_method:: POST /servers/{server_id}/os-volume_attachments

Attach a volume to an instance.

Normal response codes: 200

Error response codes: badRequest(400), unauthorized(401), forbidden(403), itemNotFound(404), conflict(409)

Request
-------

.. rest_parameters:: parameters.yaml


  - server_id: server_id_path
  - volumeAttachment: volumeAttachment
  - volumeId: volumeId
  - device: device

**Example Attach a volume to an instance: JSON request**

.. literalinclude:: ../../doc/api_samples/os-volumes/attach-volume-to-server-req.json
   :language: javascript

Response
--------

.. rest_parameters:: parameters.yaml

  - volumeAttachment: volumeAttachment
  - device: device_resp
  - id: attachment_id_resp
  - serverId: server_id
  - volumeId: volumeId_resp

**Example Attach a volume to an instance: JSON response**

.. literalinclude:: ../../doc/api_samples/os-volumes/attach-volume-to-server-resp.json
   :language: javascript

Show a detail of a volume attachment
====================================

.. rest_method:: GET /servers/{server_id}/os-volume_attachments/{attachment_id}

Show a detail of a volume attachment.

Normal response codes: 200

Error response codes: unauthorized(401), forbidden(403), itemNotFound(404)

Request
-------

.. rest_parameters:: parameters.yaml


  - server_id: server_id_path
  - attachment_id: attachment_id

Response
--------

.. rest_parameters:: parameters.yaml

  - volumeAttachment: volumeAttachment
  - device: device_resp
  - id: attachment_id_resp
  - serverId: server_id
  - volumeId: volumeId_resp

**Example Show a detail of a volume attachment: JSON response**

.. literalinclude:: ../../doc/api_samples/os-volumes/volume-attachment-detail-resp.json
   :language: javascript

Update a volume attachment
==========================

.. rest_method:: PUT /servers/{server_id}/os-volume_attachments/{attachment_id}

Update a volume attachment.

Normal response codes: 202

Error response codes: badRequest(400), unauthorized(401), forbidden(403), itemNotFound(404), conflict(409)

Request
-------

.. rest_parameters:: parameters.yaml


  - server_id: server_id_path
  - attachment_id: attachment_id
  - volumeAttachment: volumeAttachment
  - volumeId: volumeId_swap

**Example Update a volume attachment: JSON request**

.. literalinclude:: ../../doc/api_samples/os-volumes/update-volume-req.json
   :language: javascript

Response
--------

No body is returned on successful request.

Detach a volume from an instance
================================

.. rest_method:: DELETE /servers/{server_id}/os-volume_attachments/{attachment_id}

Detach a volume from an instance.

Normal response codes: 202

Error response codes: badRequest(400), unauthorized(401), forbidden(403), itemNotFound(404), conflict(409)

Request
-------

.. rest_parameters:: parameters.yaml


  - server_id: server_id_path
  - attachment_id: attachment_id

Response
--------

No body is returned on successful request.
