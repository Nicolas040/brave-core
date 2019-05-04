/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

import * as React from 'react'
import { bindActionCreators, Dispatch } from 'redux'
import { connect } from 'react-redux'

// Utils
import * as donateActions from '../actions/donate_actions'

interface Props extends RewardsDonate.ComponentProps {
  tweetMetaData: RewardsDonate.TweetMetaData
}

class TweetBox extends React.Component<Props, {}> {
  get actions () {
    return this.props.actions
  }

  formatDate = (date: Date) => {
    const dateOptions = { month: 'short', day: 'numeric' }
    if (new Date().getFullYear() !== date.getFullYear()) {
      dateOptions['year'] = 'numeric'
    }
    return date.toLocaleString(navigator.language, dateOptions)
  }

  render () {
    const tweetDate = new Date(this.props.tweetMetaData.tweetTimestamp * 1000)
    return (
      <div style={{ whiteSpace: 'pre-wrap', border: '1px solid #d3d3d3', borderRadius: '5px', margin: '20px 0 0 0', padding: '20px' }}>
        {this.formatDate(tweetDate)}
        <br/>
        {this.props.tweetMetaData.tweetText}
      </div>
    )
  }
}

const mapStateToProps = (state: RewardsDonate.ApplicationState) => ({
  rewardsDonateData: state.rewardsDonateData
})

const mapDispatchToProps = (dispatch: Dispatch) => ({
  actions: bindActionCreators(donateActions, dispatch)
})

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(TweetBox)
