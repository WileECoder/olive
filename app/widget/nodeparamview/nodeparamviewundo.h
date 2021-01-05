/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2020 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef NODEPARAMVIEWUNDO_H
#define NODEPARAMVIEWUNDO_H

#include "node/input.h"
#include "undo/undocommand.h"

namespace olive {

class NodeParamSetKeyframingCommand : public UndoCommand {
public:
  NodeParamSetKeyframingCommand(NodeInput* input, int element, bool setting, QUndoCommand* parent = nullptr);

  virtual Project* GetRelevantProject() const override;

protected:
  virtual void redo_internal() override;
  virtual void undo_internal() override;

private:
  NodeInput* input_;
  bool setting_;
  int element_;

};

class NodeParamInsertKeyframeCommand : public UndoCommand {
public:
  NodeParamInsertKeyframeCommand(NodeInput* input, NodeKeyframe* keyframe, QUndoCommand *parent = nullptr);

  virtual Project* GetRelevantProject() const override;

protected:
  virtual void redo_internal() override;
  virtual void undo_internal() override;

private:
  NodeInput* input_;

  NodeKeyframe* keyframe_;

  QObject memory_manager_;

};

class NodeParamRemoveKeyframeCommand : public UndoCommand {
public:
  NodeParamRemoveKeyframeCommand(NodeKeyframe* keyframe, QUndoCommand *parent = nullptr);

  virtual Project* GetRelevantProject() const override;

protected:
  virtual void redo_internal() override;
  virtual void undo_internal() override;

private:
  NodeInput* input_;

  NodeKeyframe* keyframe_;

  QObject memory_manager_;

};

class NodeParamSetKeyframeTimeCommand : public UndoCommand {
public:
  NodeParamSetKeyframeTimeCommand(NodeKeyframe* key, const rational& time, QUndoCommand* parent = nullptr);
  NodeParamSetKeyframeTimeCommand(NodeKeyframe* key, const rational& new_time, const rational& old_time, QUndoCommand* parent = nullptr);

  virtual Project* GetRelevantProject() const override;

protected:
  virtual void redo_internal() override;
  virtual void undo_internal() override;

private:
  NodeKeyframe* key_;

  rational old_time_;
  rational new_time_;

};

class NodeParamSetKeyframeValueCommand : public UndoCommand {
public:
  NodeParamSetKeyframeValueCommand(NodeKeyframe* key, const QVariant& value, QUndoCommand* parent = nullptr);
  NodeParamSetKeyframeValueCommand(NodeKeyframe* key, const QVariant& new_value, const QVariant& old_value, QUndoCommand* parent = nullptr);

  virtual Project* GetRelevantProject() const override;

protected:
  virtual void redo_internal() override;
  virtual void undo_internal() override;

private:
  NodeKeyframe* key_;

  QVariant old_value_;
  QVariant new_value_;

};

class NodeParamSetStandardValueCommand : public UndoCommand {
public:
  NodeParamSetStandardValueCommand(NodeInput* input, int track, int element, const QVariant& value, QUndoCommand* parent = nullptr);
  NodeParamSetStandardValueCommand(NodeInput* input, int track, int element, const QVariant& new_value, const QVariant& old_value, QUndoCommand* parent = nullptr);

  virtual Project* GetRelevantProject() const override;

protected:
  virtual void redo_internal() override;
  virtual void undo_internal() override;

private:
  NodeInput* input_;
  int element_;
  int track_;

  QVariant old_value_;
  QVariant new_value_;

};

}

#endif // NODEPARAMVIEWUNDO_H
